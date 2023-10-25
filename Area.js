
// Create a function to calculate the area of a rectangle given its windth and Height
// by normal function
function AreaofRectangle(width,height){
    return height*width;
}
console.log(AreaofRectangle(5,10))
// or 
let area = AreaofRectangle(6,10);
console.log(area);

// by arrow function


let areaofrectangle = (height,width) =>{
    return height*width;
}
console.log(areaofrectangle(4,12))
// or 
let byarrowarea = areaofrectangle(3,15);
console.log(byarrowarea)
// or 
console.log("Area of rectangle is "+byarrowarea)
