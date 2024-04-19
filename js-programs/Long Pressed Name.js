/**
 * @param {string} name
 * @param {string} typed
 * @return {boolean}
 */
var isLongPressedName = function(name, typed) {
    let c = 0;
    for(let i=0; i<typed.length; i++){
        if(c < name.length && name[c] === typed[i]) {
            c++;
        }
        else if(i === 0 || typed[i] !== typed[i-1]) {
            return false;
        }
    }
    return c === name.length;
};
