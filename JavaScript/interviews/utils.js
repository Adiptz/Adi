// utils functions for watter jugs question
// Adi Peretz - 08/29/2020


// cloning array of jugs into new array
export function cloneJugs(jugs) {
    return jugs.map(e => Object.assign({}, e));
}

// check if target jug can hold the entire quantity from the origin jug
export function shouldPourAll(fromJug, toJug) {
    return fromJug.filed + toJug.filed <= toJug.capacity;
}

// pour the entire quantity from jug to other jug
export function pourAllFromTo(jugs, from, to) {
    const offset = -1; //jugs: 1->3, array: 0->2
    const fromJug = jugs[from + offset];
    const toJug = jugs[to + offset];
    toJug.filed = fromJug.filed + toJug.filed;
    fromJug.filed = 0;
}

// pour as much as the target jug can hold
export function pourTillFullFromTo(jugs, from, to) {
    const offset = -1; //jugs: 1->3, array: 0->2
    const fromJug = jugs[from + offset];
    const toJug = jugs[to + offset];
    fromJug.filed = fromJug.filed - (toJug.capacity - toJug.filed);
    toJug.filed = toJug.capacity;
}

// check if the jug isn't empty
export function hasWater(jug) {
    return jug.filed > 0;
}

// check if the jug isn't full
export function hasFreeSpace(jug) {
    return jug.filed < jug.capacity;
}