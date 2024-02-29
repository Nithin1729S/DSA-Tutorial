const canSum=(targetSum,numbers)=>
{
    if(targetSum===0) return true;
    if(targetSum<0) return false;

    for(let num of numbers)
    {
        const rem=targetSum-num;
        if(canSum(rem,numbers)===true) return true;
    }
    return false;
}

console.log(canSum(7,[2,3]));
console.log(canSum(7,[5,4,3,7]));
console.log(canSum(7,[2,4]));