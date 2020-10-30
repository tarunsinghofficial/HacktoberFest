const generateBtn = document.getElementById("generate");
const generateSimps = document.getElementById("generate-simps");
const img = document.getElementById("img");
const quote = document.getElementById("quote");
const charName = document.getElementById("char-name");
const simpsUrl = "https://thesimpsonsquoteapi.glitch.me/quotes";
const randomUrl = "http://quotes.stormconsultancy.co.uk/random.json";

//For getting the quotes from API endpoint
async function generateQuote(url) {
  const res = await fetch(url);
  const data = await res.json();
  if (url === simpsUrl) {
    quoteDOM(data);
  } else {
    randomQuoteDOM(data);
  }
}

//For generating SIMPS quotes and displaying to window
function quoteDOM(data) {
  const quoteEl = data[0].quote;
  quote.innerText = quoteEl;
  const image = data[0].image;
  img.src = image;
  img.style.display = "flex";
  const charEl = data[0].character;
  charName.innerText = charEl;
}

//Generating Random quote
function randomQuoteDOM(data) {
  const quoteEl = data.quote;
  quote.innerText = quoteEl;
  img.style.display = "none";
  const charEl = data.author;
  charName.innerText = charEl;
}

//Event Listeners
generateBtn.addEventListener("click", () => {
  generateQuote(randomUrl);
});

generateSimps.addEventListener("click", () => {
  generateQuote(simpsUrl);
});

//generateQuote(simpsUrl);
generateQuote(randomUrl);
