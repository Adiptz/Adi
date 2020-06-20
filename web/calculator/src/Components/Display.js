import React from "react";

const Display = props => {
    const {result} = props;

    return (
        <div className="result">
            <p>{result}</p>
        </div>
    );
}

export default Display;