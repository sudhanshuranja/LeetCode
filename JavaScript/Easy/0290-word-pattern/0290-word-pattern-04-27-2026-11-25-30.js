var wordPattern = function(pattern, s) {
    const words = s.split(" ");
    if (pattern.length !== words.length) return false;

    const seen = new Map();

    for (let i = 0; i < pattern.length; i++) {
        const p = pattern[i];
        const w = words[i];

        const keyP = "p_" + p;
        const keyW = "w_" + w;

        if (seen.has(keyP) && seen.get(keyP) !== w) return false;
        if (seen.has(keyW) && seen.get(keyW) !== p) return false;

        seen.set(keyP, w);
        seen.set(keyW, p);
    }

    return true;    
};