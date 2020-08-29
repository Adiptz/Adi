const exampleJugs = [{id: 1, capacity: 12, filed: 12},
                     {id: 2, capacity: 8, filed: 0},
                     {id: 3, capacity: 5, filed: 0}];

function getStepsWaterJugs(jugs, literToMeasure) {
    let answer = [];
    const stepsVisited = {};

    recursiveGetSteps(jugs, literToMeasure, answer, stepsVisited);

    return answer.reverse(); // backtrack solution
}

function recursiveGetSteps(jugs, literToMeasure, answer, stepsVisited) {
    const jug1 = jugs[0];
    const jug2 = jugs[1];
    const jug3 = jugs[2];

    const currentStep = [jug1.filed, jug2.filed, jug3.filed];

    // got the desired measurement
    if (jug1.filed === literToMeasure || jug2.filed === literToMeasure || jug3.filed === literToMeasure) return true;

    // already been in this state
    if (stepsVisited[currentStep]) return false;

    console.log('im here');
    stepsVisited[currentStep] = 1;


    // moving water between jugs

    if (jug1.filed > 0) {
        // 1 -> 2
        if (jug2.filed < jug2.capacity) {
            if (jug1.filed + jug2.filed <= jug2.capacity) {
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = 0;
                nextJugs[1].filed = jug1.filed + jug2.filed;
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('1->2');
                    return true;
                }
            } else { // not enough space for all water from jug 1 in jug 2
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = jug1.filed - (jug2.capacity - jug2.filed);
                nextJugs[1].filed = jug2.capacity;

                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('1->2');
                    return true;
                }
            }
        }

        // 1 -> 3
        if (jug3.filed < jug3.capacity) {
            if (jug1.filed + jug3.filed <= jug3.capacity) {
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = 0;
                nextJugs[2].filed = jug1.filed + jug3.filed;
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('1->3');
                    return true;
                }
            } else { // not enough space for all water from jug 1 in jug 3
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = jug1.filed - (jug3.capacity - jug3.filed);
                nextJugs[2].filed = jug3.capacity;

                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('1->3');
                    return true;
                }
            }
        }
    }

    if (jug2.filed > 0) {
        // 2 -> 1
        if (jug1.filed < jug1.capacity) {
            if (jug2.filed + jug1.filed < jug1.capacity) {
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = jug1.filed + jug2.filed;
                nextJugs[1].filed = 0;
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('2->1');
                    return true;
                }
            } else { // not enough space for all water from jug 2 in jug 1
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = jug1.capacity;
                nextJugs[1].filed = jug2.filed - (jug1.capacity - jug1.filed);
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('2->1');
                    return true;
                }
            }
        }

        // 2->3
        if (jug3.filed < jug3.capacity) {
            if (jug2.filed + jug3.filed < jug3.capacity) {
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[1].filed = 0;
                nextJugs[2].filed = jug2.filed + jug3.filed;
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('2->3');
                    return true;
                }
            } else { // not enough space for all water from jug 2 in jug 1
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[1].filed = jug2.filed - (jug3.capacity - jug3.filed);
                nextJugs[2].filed = jug3.capacity;
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('2->3');
                    return true;
                }
            }
        }
    }

    if (jug3.filed > 0) {
        // 3 -> 1
        if (jug1.filed < jug1.capacity) {
            if (jug3.filed + jug1.filed < jug1.capacity) {
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = jug1.filed + jug3.filed;
                nextJugs[2].filed = 0;
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('3->1');
                    return true;
                }
            } else { // not enough space for all water from jug 3 in jug 1
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[0].filed = jug1.capacity;
                nextJugs[2].filed = jug3.filed - (jug1.capacity - jug1.filed);
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('3->1');
                    return true;
                }
            }
        }

        // 3 -> 2
        if (jug2.filed < jug2.capacity) {
            if (jug2.filed + jug3.filed < jug2.capacity) {
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[1].filed = jug2.filed + jug3.filed;
                nextJugs[2].filed = 0;
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('3->2');
                    return true;
                }
            } else { // not enough space for all water from jug 3 in jug 2
                const nextJugs = jugs.map(e => Object.assign({}, e));
                nextJugs[1].filed = jug2.capacity;
                nextJugs[2].filed = jug3.filed - (jug2.capacity - jug2.filed);
                if (recursiveGetSteps(nextJugs, literToMeasure, answer, stepsVisited)) {
                    answer.push('3->2');
                    return true;
                }
            }
        }
    }

    return false;
}

const result = getStepsWaterJugs(exampleJugs, 6);
console.log(result);
