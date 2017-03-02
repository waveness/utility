#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <unistd.h>
#include <sys/prctl.h>

void thread_task(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
    prctl(PR_SET_NAME, "myname");
    char name[30];
    int len = 30;
    prctl(PR_GET_NAME, name, &len);
    printf("this name is %s\n", name);
    while(1){
        sleep(1);
    }
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::thread threads[1];
    std::cout << "Spawning 1 threads...\n";
    for (int i = 0; i < 1; i++) {
        threads[i] = std::thread(thread_task, i + 1);
    }
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads) {
        t.join();
    }
    std::cout << "All threads joined.\n";

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
