document.getElementById("leftToRight").addEventListener("click", leftToRight);

function leftToRight(){
    const allLines = document.getElementsByClassName("line");
    const length = allLines.length;

    for (let i = 0; i < length ; ++i){
        allLines[i].classList.add("left_align");
    }
}

/* className = "left_align" not working*/

document.getElementById("rightToLeft").addEventListener("click", rightToLeft);

function rightToLeft(){
    const allLines = document.getElementsByClassName("line");
    const length = allLines.length;

    for (let i = 0; i < length ; ++i){
        allLines[i].classList.remove("left_align");
    }
}