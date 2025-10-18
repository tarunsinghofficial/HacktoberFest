document.addEventListener("click",(event)=>{

    // pahle ek div banao circle jiski class bhi circle ho

    const circle=document.createElement('div');
    circle.className='circle';
    circle.textContent='HI';

    document.body.appendChild(circle);

    // ab 5s baad circle hatna bhi toh chahiye

    setTimeout(()=>{
        circle.remove();
    },5000)

    // ab alag alag color ke circle bana ne chahiye toh yeh karenge

    const colors=["red","blue","green","yellow","pink","wheat","purple"];
    circle.style.backgroundColor=colors[Math.floor(Math.random()*colors.length)];

    // ab apan ko kya karna hai jaha bhi click kare waha circle ban jaana chahiye

    const x = event.clientX;
    const y = event.clientY;

    // mouse ko click karne pe uske centre pe nhi ho rha woh abhi bhi body ke centre pe kar rha hai toh uske liye apan {x-25} {y-25} lenge

    circle.style.left=`${x-25}px`;
    circle.style.top=`${y-25}px`;



    // abhi tak sab shi hai ab naye naye text bhi toh aane chahiye bhai

    const messages=["Hola","Szia","oi","привет","एहो","你好","สวัสดี","HI","नमस्ते"];
    circle.textContent=messages[Math.floor(Math.random()*messages.length)];

})