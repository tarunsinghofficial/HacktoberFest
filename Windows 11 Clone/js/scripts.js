let taskbaricons = document.getElementsByClassName("taskbaricons")[0]
let start = document.getElementsByClassName("start")[0]

taskbaricons.addEventListener("click", () => {
    if (start.style.bottom == "50px") { // bottom size chota karne ke liye
        start.style.bottom = "-655px"
    } else {
        start.style.bottom = "50px" // bottom size bada karn ke liye
    }
})

document.addEventListener('contextmenu', event => event.preventDefault());
document.addEventListener()
