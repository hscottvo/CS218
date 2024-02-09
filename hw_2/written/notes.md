# Notes

## Don't be Late

- $S = 60$ seconds
- $E = 20$ seconds

- let $W$ be the amount of time to wait

### Test Cases

#### $W = 20$

- best case: elevator comes in $[0, 20)$ seconds
  - Solution arrives at $[20, 40]$ seconds $\rarr$ $40$
- worst case: elevator comes at $20$ seconds
  - wait $20$ seconds + $S=60$ = total $80$ seconds

> $2$ times the optimal solution

#### $W = 30$

- best case: elevator comes in $[0, 30)$ seconds
  - Solution arrives at $[20, 50]$ seconds $\rarr$ $50$
- worst case: elevator comes at $30$ seconds
  - wait $30$ seconds + $S=60$ = total $90$ seconds

> $\frac{9}{5} = 1.8$ times the optimal solution

#### $W = 35$

- best case: elevator comes in $[0, 35)$ seconds
  - Solution arrives at $[20, 55]$ seconds $\rarr$ $55$
- worst case: elevator comes at $35$ seconds
  - wait $35$ seconds + $S=60$ = total $95$ seconds

> $\frac{95}{55} = 1.7272$ times the optimal solution

#### $W = 40$

- best case: elevator comes in $[0, 40)$ seconds
  - Solution arrives at $[20, 60]$ seconds $\rarr$ $60$
- worst case: elevator comes at $40$ seconds
  - wait $40$ seconds + $S=60$ = total $100$ seconds

> $\frac{5}{3} = 1.666$ times the optimal solution

#### $W = 45$

- best case: elevator comes in $[0, 45)$ seconds
  - Solution arrives at $[20, 65]$ seconds $\rarr$ $65$
  - Better to just wait $60$ seconds
- worst case: elevator comes at $45$ seconds
  - wait $45$ seconds + $S=60$ = total $105$ seconds

> $\frac{105}{60} = 1.75$ times the optimal solution 

#### $W = 50$

- best case: elevator comes in $[0, 50)$ seconds
  - Solution arrives at $[20, 70]$ seconds $\rarr$ $70$
  - would have been better to wait $60$ seconds
- worst case: elevator comes at $50$ seconds
  - wait $50$ seconds + $S=60$ = total $110$ seconds

> $\frac{11}{6} = 1.833$ the optimal solution
