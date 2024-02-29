const gridTravellor=(m,n,memo={})=>
{
    const key=m+','+n;
    if(key in memo) return memo[key];
    
    if(m===1&&n===1) return 1;
    if(m===0 || n===0) return 0;

    memo[key]=gridTravellor(m-1,n,memo)+gridTravellor(m,n-1,memo);
    return memo[key];
}

console.log(gridTravellor(1,1));
console.log(gridTravellor(2,3));
console.log(gridTravellor(3,2));
console.log(gridTravellor(3,3));
console.log(gridTravellor(18,18));
