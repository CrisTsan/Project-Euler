let multipliesTill n limit = 
    let numbers = limit/n
    in n*(1+numbers)*numbers/2

let solution =
    multipliesTill 3 999
    + multipliesTill 5 999 
    - multipliesTill 15 999


