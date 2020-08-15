import React, {Component} from "react";
import NumberDisplay from "../NumberDisplay/NumberDisplay";

// simple stateful class component
class Task2 extends Component {
    constructor(props) {
        super(props);
        this.state = {
            number: this.props.number
        };
    }

    increaseByOne = () => {
        this.setState(prevState => ({number: prevState.number + 1}));
    }

    render() {
        return (
            <NumberDisplay
                number={this.state.number}
                onClick={this.increaseByOne}
            />
        )
    }
}

export default Task2;