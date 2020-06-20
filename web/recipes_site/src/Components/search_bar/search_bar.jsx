import React, {useState} from "react";

const SearchBar = (props) => {
    const [search, setSearch] = useState('');

    return (
        <form className="search-form">
            <input
                type="text"
                value={search}
                onChange={(e) => {
                    setSearch(e.target.value);
                }}
            />

            <button type="button" onClick={() => props.onSubmit(search)}>
                Search
            </button>
        </form>
    );
};

export default SearchBar;