const canvas=document.querySelector('canvas');
const ctx = canvas.getContext('2d');
const scoreEl=document.querySelector('#score');
const button=document.querySelector('button');
const startBody=document.querySelector('.start');
const bigscore=document.querySelector('.bigscore');
var audio = new Audio('laser.mp3');
var audio1 = new Audio('rail.mp3');




canvas.width=innerWidth;
canvas.height=innerHeight;

console.log(ctx);

class Player{
    constructor(x,y,radius,color){
        this.x=x;
        this.y=y;
        this.radius=radius;
        this.color=color;
    }

  
       
  draw(){
        ctx.beginPath()
        ctx.arc(this.x, this.y, this.radius,0,Math.PI*2,false)
        ctx.fillStyle = this.color;
        ctx.fill();
    }

}

class Projectile{
    constructor(x,y,radius,color,velocity){
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.color = color;
        this.velocity = velocity;
    }
    draw(){
        ctx.beginPath()
        ctx.arc(this.x, this.y, this.radius,0,Math.PI*2,false)
        ctx.fillStyle = this.color;
        ctx.fill();
    }
    update(){
        this.draw();
        this.x = this.x + this.velocity.x;
        this.y = this.y + this.velocity.y;
    }
}
class Enemy{
    constructor(x,y,radius,color,velocity){
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.color = color;
        this.velocity = velocity;
    }
    draw(){
        ctx.beginPath()
        ctx.arc(this.x, this.y, this.radius,0,Math.PI*2,false)
        ctx.fillStyle = this.color;
        ctx.fill();
    }
    update(){
        this.draw();
        this.x = this.x + this.velocity.x;
        this.y = this.y + this.velocity.y;
    }
}
const friction=0.99;
class Particle{
    constructor(x,y,radius,color,velocity){
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.color = color;
        this.velocity = velocity;
        this.alpha=1;
    }
    draw(){
        ctx.save();
        ctx.globalAlpha = this.alpha;
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.radius,0,Math.PI*2,false);
        ctx.fillStyle = this.color;
        ctx.fill();
        ctx.restore();
    }
    update(){
        this.draw();
        this.velocity.x *= friction;
        this.velocity.y *= friction;

        this.x = this.x + this.velocity.x;
        this.y = this.y + this.velocity.y;
        this.alpha-=0.01
    }
}

const x= canvas.width/2;
const y= canvas.height/2;

//---------------------------------------------
let player=new Player(x,y,10,'white');
let projectiles=[]
let enemies=[]
let smallParticles = []
let score=0;


function init(){
    player=new Player(x,y,10,'white');
    projectiles=[]
    enemies=[]
    smallParticles = []
score=0
scoreEl.innerHTML=score
}


function enemy(){
    setInterval(()=>{
        const radius = Math.random()*(50-5)+4;
        let x;
        let y;
        if(Math.random()<0.5){
        x= Math.random()<0.5 ? 0-radius :canvas.width+radius ;
        y= Math.random() *canvas.height+radius ;
        }
        else{
            x= Math.random()+canvas.width ;
            y= Math.random()<0.5 ? 0-radius :canvas.height+radius  ;

        }

         const color=`hsl(${Math.random()*360},50%,50%)`;
        const angle=Math.atan2(canvas.height/2-y,canvas.width/2-x)
    
        const velocity={
            x:Math.cos(angle),
            y:Math.sin(angle)
    
        }
        enemies.push(new Enemy(x,y,radius, color,velocity))
    } , 1000)
}

let animationId

function animate(){
    audio1.play();
    animationId=  requestAnimationFrame(animate);
ctx.fillStyle='rgba(0,0,0,0.1)';
    ctx.fillRect(0,0,canvas.width,canvas.height);
    player.draw()
    smallParticles.forEach((particle,index)=>{
        if(particle.alpha<=0){
            smallParticles.splice(index,1)
        }else{
            particle.update();
        }
       
    })
   projectiles.forEach((projectile,projectileIndex)=>{
       projectile.update()

       //remove from edges of screen
       if(projectile.x +projectile.radius<0||
        projectile.x-projectile.radius>canvas.width||
        projectile.y+projectile.radius<0||
        projectile.y-projectile.radius>canvas.height
        ){
        setTimeout(()=>{
            
            projectiles.splice(projectileIndex,1);
        },0)
         

       }
   })
   enemies.forEach((enemy,index)=>{
       enemy.update()
//end 
       const distance=Math.hypot(player.x-enemy.x,player.y-enemy.y);
       if (distance-enemy.radius-player.radius < 1){
           cancelAnimationFrame(animationId);
           startBody.style.display = 'flex'

           bigscore.innerHTML=score;

       }


       projectiles.forEach((projectile,projectileIndex)=>{
           const distance=Math.hypot(projectile.x-enemy.x,projectile.y-enemy.y)
           // when emeney touch
           if (distance-enemy.radius-projectile.radius < 1)
           {

//create bomb
               for (let i=0;i<enemy.radius*2;i++){
                   smallParticles.push(new Particle(projectile.x,projectile.y,Math.random()*2,enemy.color,{
                       x:(Math.random()-0.5)*(Math.random()*5),
                       y:(Math.random()-0.5)*(Math.random()*5),

                   }))
               }
               if(enemy.radius-10>5){
                   //inscrease score
 score += 50
 scoreEl.innerHTML=score

 
                   enemy.radius -= 10;
                   projectiles.splice(projectileIndex,1);
               }
               else{ setTimeout(()=>{
                   //inscrease score
 score += 100
 scoreEl.innerHTML=score
 
                enemies.splice(index,1);
                projectiles.splice(projectileIndex,1);
               
            },0)}

           
             
           }
       })
   })
}

window.addEventListener('click',(e)=>{
    const angle=Math.atan2(e.clientY-canvas.height/2,e.clientX-canvas.width/2)
    
    const velocity={
        x:Math.cos(angle)*7,
        y:Math.sin(angle)*7

    }

    projectiles.push(
        new Projectile(canvas.width/2,canvas.height/2,5,'white',velocity )
    )
    audio.currentTime=0;
        audio.play();
        audio.currentTime=0;
        
    
    
 
});
button.addEventListener('click',()=>{
   
init();
animate();
enemy();
startBody.style.display = 'none'

});
