function convert(x) {
    if (x >= 1000000) {
        x = Math.round(x/1000)+"m";
    } else if (x >= 1000) {
        x = Math.round(x/1000)+"k";
    }
    return x;
}

console.log(convert(1000000));