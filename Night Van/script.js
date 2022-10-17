
    document.getElementById("song").play();

    

document.onkeydown = function (e){
    console.log(e.keyCode);
    
    if(e.keyCode==72){
        img = document.querySelector('img');
        img.src= 'Img_05.png';
    }
    if(e.keyCode==79){
        img = document.querySelector('img');
        img.src= 'Img_06.png';
    }


}

