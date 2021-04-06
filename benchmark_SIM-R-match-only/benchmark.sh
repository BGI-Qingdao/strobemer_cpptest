#!/bin/bash
#make clean
#make

function run_1_round() {
    err_rate=$1
    ./rmutation100k $err_rate  <ref100k.fa >"ref100k_mu"$err_rate".fa"

    ### test k 30
    ./gen_kmer   30  <ref100k.fa >k30.all
    KM=`./check_kmer 30  k30.all <"ref100k_mu"$err_rate".fa"`
    echo "kmer30_match $err_rate $KM"
    ### test minstrobe (2,15,50)
    ./gen_minstrobe <ref100k.fa >min.all
    MM=`./check_minstrobe min.all <"ref100k_mu"$err_rate".fa"`
    echo "gen_minstrobe_2_15_50 $err_rate $MM"

    ### test randstrobe (2,15,50)
    ./gen_randstrobe <ref100k.fa >rand.all
    RM=`./check_randstrobe rand.all <"ref100k_mu"$err_rate".fa"`
    echo "gen_ranstrobe_2_15_50 $err_rate $RM"
}

function run100(){
    err_rate=$1
    for i in {1..10}
    do
        ./random100k >ref100k.fa
        for j in {1..10}
        do
            run_1_round $err_rate
        done
    done
}

# echo result header
echo "type error match"
# test error rate 1/100
run100 10
# test error rate 5/100
run100 50
# test error rate 10/100
run100 100
