const input = document.querySelector('input');
const preview = document.querySelector('.file_list');

const algorithm_path = document.querySelector('algorithm_path');

function showTextFile() {

    console.log("파일 읽어오기");

    const selectedFiles = input.files;
    const list = document.createElement('ul');
    preview.appendChild(list);
 
    for(var i = 0;i < selectedFiles.length;i++){
        console.log(input.files[i].name);
    }


    for(const file of selectedFiles) {
        const listItem = document.createElement('li');
        const summary = document.createElement('div');
 
        summary.textContent = file.webkitRelativePath;
 
        listItem.appendChild(summary);
        list.appendChild(listItem);

        console.log(input.files.item + "/" + listItem.Child + "/" +summary);
    }
}


window.onload = function(){
    //input.addEventListener('change', showTextFile);

}