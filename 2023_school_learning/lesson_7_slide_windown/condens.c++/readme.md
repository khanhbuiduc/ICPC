# WH35. CÔ ĐẠC (CONDENS)

## Định lý Lucas

Cho số nguyên tố p và các số nguyên không âm m, n. Ta có:

```
C(m,n) ≡ ∏C(mi, ni) (mod p)
```

trong đó mi, ni là các chữ số của m, n khi viết trong hệ cơ số p.

## Ý tưởng giải bài

1. Quá trình cô đặc xâu nhị phân tương đương với việc tính tổng có trọng số
2. Ký tự s[i] có trọng số là C(n-1, i) mod 2 (n là độ dài xâu)
3. Áp dụng định lý Lucas với p=2:
   - C(n-1, i) mod 2 = 1 ⟺ (n-1) & i = i
   - Tức là tất cả các bit 1 trong i cũng phải là bit 1 trong (n-1)
4. Kết quả = XOR của tất cả s[i] thỏa mãn điều kiện trên

## Ví dụ

Với s = "11010" (n=5, n-1=4=100₂):

- i=0 (000₂): 4&0=0=0 ✓ → s[0]='1'
- i=1 (001₂): 4&1=0≠1 ✗
- i=2 (010₂): 4&2=0≠2 ✗
- i=3 (011₂): 4&3=0≠3 ✗
- i=4 (100₂): 4&4=4=4 ✓ → s[4]='0'

Kết quả = s[0] XOR s[4] = '1' XOR '0' = '1'
