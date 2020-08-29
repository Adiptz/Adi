// Adi Peretz | 08/29/2020 | Rewire - Interview with Adi Ben-Dayan

import {cloneJugs, hasFreeSpace, hasWater, pourAllFromTo, pourTillFullFromTo, shouldPourAll} from './utils.js';

function getStepsWaterJugs(jugs, litersToMeasure) {
    let answer = [];
    const stepsVisited = {};

    recursiveGetSteps(jugs, litersToMeasure, answer, stepsVisited);

    return answer.reverse(); // backtrack solution
}

function recursiveGetSteps(jugs, litersToMeasure, answer, stepsVisited) {
    const jug1 = jugs[0];
    const jug2 = jugs[1];
    const jug3 = jugs[2];
    let returnValue;
    const currentStep = [jug1.filed, jug2.filed, jug3.filed];

    // already been in this state
    if (stepsVisited[currentStep]) return false;

    // got the desired measurement
    if (jug1.filed === litersToMeasure || jug2.filed === litersToMeasure || jug3.filed === litersToMeasure) return true;

    stepsVisited[currentStep] = 1; //mark this step as visited

    // move water between jugs
    if (hasWater(jug1)) {
        // 1 -> 2
        returnValue = pourFromTo(1, 2, jugs, litersToMeasure, answer, stepsVisited);
        if (returnValue) return true;

        // 1 -> 3
        returnValue = pourFromTo(1, 3, jugs, litersToMeasure, answer, stepsVisited);
        if (returnValue) return true;
    }

    if (hasWater(jug2)) {
        // 2 -> 1
        returnValue = pourFromTo(2, 1, jugs, litersToMeasure, answer, stepsVisited);
        if (returnValue) return true;

        // 2 -> 3
        returnValue = pourFromTo(2, 3, jugs, litersToMeasure, answer, stepsVisited);
        if (returnValue) return true;
    }

    if (hasWater(jug3)) {
        // 3 -> 1
        returnValue = pourFromTo(3, 1, jugs, litersToMeasure, answer, stepsVisited);
        if (returnValue) return true;

        // 3 -> 2
        returnValue = pourFromTo(3, 2, jugs, litersToMeasure, answer, stepsVisited);
        if (returnValue) return true;
    }
}

// the main action in this algorithm: pouring water from one jug to another
function pourFromTo(from, to, jugs, litersToMeasure, answer, stepsVisited) {
    const offset = -1; // array: 0 -> 2, jars: 1 -> 3
    const fromJug = jugs[from + offset];
    const toJug = jugs[to + offset];

    if (hasFreeSpace(toJug)) {
        const nextJugsState = cloneJugs(jugs);

        if (shouldPourAll(fromJug, toJug)) {
            pourAllFromTo(nextJugsState, from, to);
            if (recursiveGetSteps(nextJugsState, litersToMeasure, answer, stepsVisited)) {
                answer.push(`${fromJug.id} -> ${toJug.id}`);
                return true;
            }
        } else { // not enough space for all water in one toJug
            pourTillFullFromTo(nextJugsState, from, to);
            if (recursiveGetSteps(nextJugsState, litersToMeasure, answer, stepsVisited)) {
                answer.push(`${fromJug.id} -> ${toJug.id}`);
                return true;
            }
        }
    }
}

const testJugs = [
    {id: 1, capacity: 12, filed: 12},
    {id: 2, capacity: 8, filed: 0},
    {id: 3, capacity: 5, filed: 0}
];
console.log(getStepsWaterJugs(testJugs, 3));


