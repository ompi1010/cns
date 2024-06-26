//User A want to communicate to user B but they want to user Asymmetric Key Cryptography by using
//RSA algorithms send message to each other.encrypt message at sender side and decrypt it at receiver
//side
#include<stdio.h> 
long long int power(long long int base, long long int expo, long long int modulus) 
{
    long long int result = 1;
    while (expo > 0) 
    {
        if (expo % 2 == 1) 
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        expo /= 2;
    }
    return result;
}
long long int encrypt(long long int plaintext, long long int e, long long int n) 
{
    return power(plaintext, e, n);
}
long long int decrypt(long long int ciphertext, long long int d, long long int n) 
{
    return power(ciphertext, d, n);
}
int main() 
{
    long long int p, q, n, phi, e,d=1;
    printf("Enter prime number p: ");
    scanf("%lld", &p);
    printf("Enter prime number q: ");
    scanf("%lld", &q);
    n = p * q;
    phi = (p - 1) * (q - 1);
    printf("Enter public exponent e (such that 1 < e < phiNo and e is coprime to phiNo): ");
    scanf("%lld", &e);
    while (((d * e) % phi) != 1) 
    {
        d++;
    }
    long long int plaintext;
    printf("Enter plaintext message: ");
    scanf("%lld", &plaintext);
    long long int ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted message: %lld\n", ciphertext);
    long long int decryptedtext = decrypt(ciphertext, d, n);
    printf("Decrypted message: %lld\n", decryptedtext);
    return 0;
}