// if you want to do a first time set up in an application and want to change its behavior all over
{
    let scareMe = function () {
        console.log("Boo!");
        scareMe = function () { //define it with var
            console.log("Double boo!");
        }
    };

    scareMe();
    scareMe();
}
