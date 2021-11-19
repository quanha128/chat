#include <stdio.h>

double per_hop_delay(double proc_delay, double queue_delay, double link_distance, double propagation_speed,
                     double pkt_len, double transmission_rate) {
    double prop_delay = link_distance / propagation_speed;
    double trans_delay = (pkt_len*8) / transmission_rate;
    return proc_delay + queue_delay + prop_delay + trans_delay;
}

int main(){
    double proc_d = 0.001;
    double queue_d = 0.01;
    double link_dis = 100000;
    double prop_speed = 3*100000000;
    double pkt_size = 1500;
    double trans_rate = 10*1000*1000;
    printf("Per-hop delay is %f\n", per_hop_delay(proc_d, queue_d, link_dis, prop_speed, pkt_size, trans_rate));
    return 0;
}