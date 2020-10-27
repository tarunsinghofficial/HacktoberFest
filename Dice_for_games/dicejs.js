var randomNumber1=Math.floor(Math.random()*6)+1;
var diceImg="images/dice"+randomNumber1+".png";
var img1=document.querySelectorAll("img")[0];
img1.setAttribute("src",diceImg);

var randomNumber2=Math.floor(Math.random()*6)+1;
var diceImg="images/dice"+randomNumber2+".png";
var img2=document.querySelectorAll("img")[1];
img2.setAttribute("src",diceImg);

if(randomNumber1>randomNumber2)
document.querySelector("h1").innerHTML="🚩Player 1 wins";

else if(randomNumber2>randomNumber1)
document.querySelector("h1").innerHTML="🚩Player 2 wins";

else
document.querySelector("h1").innerHTML="🚩It's a tie";