#!/usr/bin/env python3

from fractions import gcd
import rsa

def main():

    alice_pub="alice-pub.pem"
    bob_pub="bob-pub.pem"
    with open(alice_pub, "rb") as pubkeyfile:
        pubkeydata = pubkeyfile.read()
    n1 = rsa.PublicKey.load_pkcs1_openssl_pem(pubkeydata).n
    print("n1 = "+str(n1))
    
    with open(bob_pub, "rb") as pubkeyfile:
        pubkeydata = pubkeyfile.read()
    n2 = rsa.PublicKey.load_pkcs1_openssl_pem(pubkeydata).n

    print("n2 = "+str(n2))
    
    p=gcd(n1,n2)
    # greatest common divisor
    print("gcd(n1,n2) = "+str(p))
    # integer divison
    print("n1/p = "+str(n1//p))

# end of main

if __name__ == "__main__":
    main()
