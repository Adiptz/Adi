import React, {useState} from "react";

const SearchBar = ({onSearch}) => {
    // const [search, setSearch] = useState('');
    function debounce(func, wait) {
        let timeout;
        return function () {
            const context = this, args = arguments;

            let later = function () {
                timeout = null;
                func.apply(context, args);
            };

            clearTimeout(timeout);
            timeout = setTimeout(later, wait);


        };
    }

    const debounceSearch = debounce(onSearch, 400);

    return (
        <div className="search-form">
            <input
                placeholder={`What are you looking for?..`}
                type="text"
                // value={search}
                onChange={(e) => {
                    debounceSearch(e.target.value);
                }}
            />
        </div>
    );
};

export default SearchBar;