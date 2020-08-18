import React, {useReducer} from "react";
import FormControlLabel from "@material-ui/core/FormControlLabel";
import Checkbox from "@material-ui/core/Checkbox";


const CheckBox = ({ComponentToRender, label, handleCheck}) => {
    const [checked, toggle] = useReducer(
        checked => !checked,
        false
    );

    return (
        <>
            <FormControlLabel
                control={
                    <Checkbox checked={checked} onChange={toggle}/>
                }
                label={<b>{label}</b>}
            />

            {checked ? ComponentToRender : ''}
        </>
    );

}

export default CheckBox;