import { example } from './example'

const parsePassport = (passport: string) => {
  const parts = passport.split('\n')
  const parts2 = parts.flatMap((x) => x.split(' '))
  const data: Record<string, string> = {}
  parts2.map((x: string) => {
    const [key, value] = x.split(':')
    data[key] = value
  })
  return data
}

const isRange = (min: number, max: number) => (raw: string) => {
  const val = parseInt(raw, 10)
  if (isNaN(val)) return false
  if (val < min || val > max) {
    return false
  }
  return true
}

const validators: Record<string, (raw: string) => boolean> = {
  byr: (raw) => {
    if (raw.length !== 4) return false
    return isRange(1920, 2002)(raw)
  },
  iyr: (raw) => {
    if (raw.length !== 4) return false
    return isRange(2010, 2020)(raw)
  },
  eyr: (raw) => {
    if (raw.length !== 4) return false
    return isRange(2020, 2030)(raw)
  },
  hgt: (raw) => {
    let split = raw.split('cm')
    if (split.length === 2) {
      return isRange(150, 193)(split[0])
    } else {
      split = raw.split('in')
      if (split.length === 2) {
        return isRange(59, 76)(split[0])
      }
    }
    return false
  },
  hcl: (raw) => {
    if (!raw.startsWith('#')) return false
    return /^#[0-9a-f]{6}$/i.test(raw)
  },
  ecl: (raw) => {
    const set = new Set(['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'])
    return set.has(raw)
  },
  pid: (raw) => {
    if (raw.length !== 9) return false
    return /^[0-9]{9}$/i.test(raw)
  },
}

const isValid = (passport: Record<string, string>) => {
  for (const field in validators) {
    const isValid = validators[field] as (raw: string) => boolean
    if (!passport[field]) return false
    const valid = isValid(passport[field])
    if (!valid) {
      return false
    }
  }
  return true
}

const main = () => {
  const rawPassports = example.split('\n\n')
  const passports = rawPassports.map(parsePassport)
  const valid = passports.filter(isValid)

  console.log(valid.length)
}
export default main
