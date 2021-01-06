import { example } from './4/example'

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

const fields = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid']

const isValid = (passport: Record<string, string>) => {
  for (const field of fields) {
    if (!(field in passport)) {
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
