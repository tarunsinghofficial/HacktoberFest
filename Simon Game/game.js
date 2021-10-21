// variables of colors and sequence pattern
var buttonColor = ["green", "red", "yellow", "blue"];
var randomChosenColor;
var gamepattern = [];
var randomNumber;
var userInput = [];
var level = 0;
var started = false;

function AnimatePress(coloring) {
    $("." + coloring).addClass("pressed");
    setInterval(function() {

        $("." + coloring).removeClass("pressed");
    }, 100);
}

function audio(color) {
    var audio = new Audio("sounds/" + color + ".mp3");
    audio.play();
}

function nextSequence() {
    // random  numbers between 0-3(color) and storing them in the empty array
    userInput = [];
    level++;
    $("h1").html("Level " + level);
    randomNumber = Math.floor(Math.random() * 4)
    randomChosenColor = buttonColor[randomNumber];
    gamepattern.push(randomChosenColor);
    console.log(gamepattern);
}

function chioce() {
    var i = 0;
    var pepet = setInterval(function() {
        if (i >= gamepattern.length) {
            clearInterval(pepet);
        }
        var button = $("#" + gamepattern[i]);
        console.log(button);
        button.fadeIn(100).fadeOut(100).fadeIn(100);
        audio(gamepattern);
        i++;
    }, 500);
}

function checking(userchecking) {
    if (userInput[userchecking] == gamepattern[userchecking]) {
        console.log("success");

        if (userInput.length === gamepattern.length) {
            setInterval(repeating(), 1000);
        }

    } else {
        audio("wrong");
        $("H1").html("Start over");
        console.log("wrong");
        $("body").addClass("game-over");
        setTimeout(function() {
            $("body").removeClass("game-over");
        }, 100);
        setTimeout(function() {
            location.reload();
        }, 500);
    }
}

$(".btn").click(function() {
    var clickedNow = $(this).attr("id");
    userInput.push(clickedNow);
    console.log(clickedNow);
    audio(clickedNow);
    AnimatePress(clickedNow);

    checking(userInput.length - 1);
});

$(document).keypress(function() {
    console.log("preesed");
    nextSequence();
    chioce();
});

function repeating() {
    nextSequence();
    chioce();
}