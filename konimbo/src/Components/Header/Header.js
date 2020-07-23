import React from "react";
import SearchBar from "../SearchBar/SearchBar";
const Header = () => {
    var prevScrollpos = window.pageYOffset;
    window.onscroll = function() {
        var currentScrollPos = window.pageYOffset;
        if (prevScrollpos > currentScrollPos) {
            document.getElementById("fixed-header").style.top = "0";
        } else {
            document.getElementById("fixed-header").style.top = "-180px";
        }
        prevScrollpos = currentScrollPos;
    }

    return (
        <div id="fixed-header">
            <h1 id='title'>Konimbo!</h1>
        </div>
    );
}

export default Header;