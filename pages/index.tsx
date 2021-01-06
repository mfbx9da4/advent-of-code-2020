import Link from 'next/link'
import { useEffect } from 'react'
import solution from '../2020/4'

const IndexPage = () => {
  useEffect(solution)
  return <pre>{JSON.stringify({}, null, 2)}</pre>
}

export default IndexPage
