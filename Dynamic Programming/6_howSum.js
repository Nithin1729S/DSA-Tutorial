const howSum=(targetSum,numbers)=>
{
    if(targetSum===0) return [];
    if(targetSum<0) return null;

    for(let num of numbers)
    {
        const rem=targetSum-num;
        const remRes=howSum(rem,numbers);
        if(remRes!=null)
        {
            return[...remRes,num];
        }
    }
    return null;
};

console.log(howSum(7,[2,3,1]));