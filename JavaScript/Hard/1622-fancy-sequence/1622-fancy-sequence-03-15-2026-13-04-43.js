class Fancy {
    constructor() {
        this.MOD = 1000000007n;
        this.seq = [];
        this.mul = 1n;
        this.add = 0n;
    }

    modInv(x) {
        return this.modPow(x, this.MOD - 2n);
    }

    modPow(base, exp) {
        let result = 1n;
        base %= this.MOD;

        while (exp > 0n) {
            if (exp % 2n === 1n) result = (result * base) % this.MOD;
            base = (base * base) % this.MOD;
            exp /= 2n;
        }
        return result;
    }

    append(val) {
        val = BigInt(val);
        let normalized = ((val - this.add + this.MOD) % this.MOD * this.modInv(this.mul)) % this.MOD;
        this.seq.push(normalized);
    }

    addAll(inc) {
        this.add = (this.add + BigInt(inc)) % this.MOD;
    }

    multAll(m) {
        m = BigInt(m);
        this.mul = (this.mul * m) % this.MOD;
        this.add = (this.add * m) % this.MOD;
    }

    getIndex(idx) {
        if (idx >= this.seq.length) return -1;
        let val = this.seq[idx];
        return Number((val * this.mul + this.add) % this.MOD);
    }
}