#!/bin/bash
#make clean
#make

function run_1_round() {
    err_rate=$1
    ./rmutation100k $err_rate  <ref100k.fa >"ref100k_mu"$err_rate".fa"

    ### test k 30
    ./gensnp_kmer   30  <ref100k.fa >k30.all
    ./checksnp_kmer 30  k30.all <"ref100k_mu"$err_rate".fa" >tmp_k 2>err 
    KM=`wc -l tmp_k| awk '{print $1}'`
    KSNP=`cut -f 2 tmp_k | uniq -c | wc -l`
    echo "kmer30_match $err_rate $KM $KSNP"
    ### test minstrobe (2,15,50)
    ./gensnp_minstrobe <ref100k.fa >min.all
    ./checksnp_minstrobe min.all <"ref100k_mu"$err_rate".fa" >tmp_m 2>err
    MM=`wc -l tmp_m| awk '{print $1}'`
    MSNP=`cut -f 2 tmp_m | uniq -c | wc -l`
    echo "gen_minstrobe_2_15_50 $err_rate $MM $MSNP"

    ### test randstrobe (2,15,50)
    ./gensnp_randstrobe <ref100k.fa >rand.all
    ./checksnp_randstrobe rand.all <"ref100k_mu"$err_rate".fa" >tmp_r 2>err
    RM=`wc -l tmp_r | awk '{print $1}'`
    RSNP=`cut -f 2 tmp_r | uniq -c | wc -l`
    echo "gen_ranstrobe_2_15_50 $err_rate $RM $RSNP"
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
echo "type error match snp"
# test error rate 1/100
run100 10
# test error rate 5/100
run100 50
# test error rate 10/100
run100 100
