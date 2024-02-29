const howSum=(targetSum,numbers,memo={})=>
{
    if(targetSum in memo) return memo[targetSum];
    if(targetSum===0) return [];
    if(targetSum<0) return null;

    for(let num of numbers)
    {
        const rem=targetSum-num;
        const remRes=howSum(rem,numbers,memo);
        if(remRes!=null)
        {
            memo[targetSum]=[...remRes,num];
            return memo[targetSum];
        }
    }
    memo[targetSum]=null;
    return null;
};

console.log(howSum(7,[2,3,1]));
console.log(howSum(300,[99,3,1]));