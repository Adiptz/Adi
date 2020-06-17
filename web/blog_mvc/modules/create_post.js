import {createElement} from "../utils.js";

const newBoxModule = (function (){

    function createNewPost (newPost){
        const article =  createElement('article', 'post');

        //title
        const h3 = createElement('h3', null, 'post_title');
        h3.textContent = newPost.title;

        //body
        let p = createElement('p', null ,'post_content');
        p.textContent = newPost.body;

        //hr
        const hr = createElement('hr', null, 'hrPost');

        //buttons
        const delete_button = createElement('button', null, 'delete_button');
        const edit_button = createElement('button', null, 'edit_button');

        const delete_image = createElement('img', null, 'delete_image');
        delete_image.src = 'images/buttons/trash.svg';
        delete_button.appendChild(delete_image);

        const edit_image = createElement('img', null, 'edit_image');
        edit_image.src = 'images/buttons/edit.svg';
        edit_button.appendChild(edit_image);

        const buttons_div = createElement('div', 'share_div', null);
        buttons_div.appendChild(delete_button);
        buttons_div.appendChild(edit_button);


        //append elements
        article.appendChild(h3);
        article.appendChild(p);
        article.appendChild(hr);
        article.appendChild(buttons_div);

        return article;
    }

    return {
        createNewPost,
    }
})();

export default newBoxModule;