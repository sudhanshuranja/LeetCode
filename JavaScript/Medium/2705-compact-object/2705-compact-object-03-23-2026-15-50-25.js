/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    
    // If it's an array
    if (Array.isArray(obj)) {
        const result = [];
        
        for (let val of obj) {
            if (val) {
                const compacted = compactObject(val);
                result.push(compacted);
            }
        }
        
        return result;
    }
    
    // If it's an object
    else if (obj !== null && typeof obj === "object") {
        const result = {};
        
        for (let key in obj) {
            if (obj[key]) {
                const compacted = compactObject(obj[key]);
                result[key] = compacted;
            }
        }
        
        return result;
    }
    
    // Primitive value
    return obj;
};