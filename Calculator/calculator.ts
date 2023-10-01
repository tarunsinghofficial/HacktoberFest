#! /usr/bin/env node
import inquirer from "inquirer";
import chalk from "chalk";
import chalkAnimation from "chalk-animation";


const sleep = () => new Promise((resolve) => setTimeout(resolve, 1000));

const performCalculation = (num1: number, num2: number, operator: string) => {
    let result: number = 0;
    if (operator === "+") {
        result = num1 + num2;
    }
    else if (operator === "-") {
        result = num1 - num2;
    }
    else if (operator === "x") {
        result = num1 * num2;
    }
    else if (operator === "÷") {
        result = num1 / num2;
    }
    return result;
}


async function showText() {
    let text = chalkAnimation.rainbow("Calculator");
    await sleep();
    text.stop();
    displayCalculator("Made by", "", "", "Usman Faizyab")
}

async function getInputs() {
    let operator: string = await inquirer.prompt(
        {
            type: "list",
            name: "operator",
            message: "Select an operator: ",
            choices: ["+", "-", "x", "÷"]
        }
        )
        .then((answers) => {
            displayCalculator(" ___", "___", answers.operator, "");
            return answers.operator;
    });


    let num1: number = await inquirer.prompt(
        {
            type: "number",
            name: "num1",
            message: "Enter first number: "
        }
        )
        .then((answers) => {
            displayCalculator(answers.num1.toString(), "___", operator, "");
            return answers.num1;
    });

    let num2: number = await inquirer.prompt(
        {
            type: "number",
            name: "num1",
            message: "Enter second number: "
        }
        )
        .then((answers) => {
            displayCalculator(num1.toString(), answers.num1.toString(), operator, "");
            return answers.num1;
    });

    let answer: number = performCalculation(num1, num2, operator);
    displayCalculator(num1.toString(), num2.toString(), operator, answer.toString());
    calculateAgain();
}

function displayCalculator(num1:string, num2:string, operator:string, result:string) {
    let exp: string = num1 + " " + operator + " " + num2;
    exp = exp.padEnd(21);
    let res = result.padStart(21);
    console.log(chalk.greenBright(`
     _________________________
    |  _____________________  |
    | |${chalk.magentaBright(exp)}| |
    | |${chalk.red(res)}| |
    | |_____________________| |
    |    ___ ___ ___   ___    |
    |   | 7 | 8 | 9 | | + |   |
    |   |___|___|___| |___|   |
    |   | 4 | 5 | 6 | | - |   |
    |   |___|___|___| |___|   |
    |   | 1 | 2 | 3 | | x |   |
    |   |___|___|___| |___|   |
    |   | . | 0 | = | | / |   |
    |   |___|___|___| |___|   |
    |_________________________|
    `))
}

async function calculateAgain() {
    let again: string = await inquirer.prompt(
        {
            type: "list",
            name: "value",
            message: "Do you want to calculate again?",
            choices: ["Yes", "No"]
        }
    ).then((answers) => {
        return answers.value
    })
    
    if (again === "Yes") {
        displayCalculator(" ____", "_____", "__", "")
        getInputs()
    }
}

await showText();
getInputs();