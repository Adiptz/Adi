function removeDuplicates(arr) {
    const result = [];
    const histogram = {};

    arr.forEach(e => {
        histogram[e] = 1;
    })

    for (let key in histogram) {
        result.push(Number(key));
    }

    return result;
}

export {removeDuplicates}