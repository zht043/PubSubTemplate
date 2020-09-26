/* Author: Hongtao Zhang */ 
#pragma once
 
#include <iostream>
#include "PubSubModule/inter_thread_pubsub.hpp"
#include "PubSubModule/oop_observer.hpp"
#include "PubSubModule/thread_pool.hpp"

class Module {
    public:
        Module() {

        }
        ~Module() {

        }

        virtual void task() = 0;
        virtual void task(ThreadPool& thread_pool) = 0;
        
        //======================Create New Thread Version=================================//
        /* create a new thread and run the module in that thread */
        void run() {
            mthread = boost::shared_ptr<boost::thread>(
                new boost::thread(boost::bind(&Module::task, this))
            );
        }
        /* don't use this method if the threadpool version of Module::run() was used */
        void idle() {
            mthread->yield(); 
        }

        /* don't use this method if the threadpool version of Module::run() was used */
        void join() {
            mthread->join();
        }
        //================================================================================//




        //============================Thread Pool Version=================================//
        /* run the module as a task to be queued for a thread pool*/
        void run(ThreadPool& thread_pool) {
            thread_pool.execute(boost::bind(&Module::task, this, boost::ref(thread_pool)));
        }
        //================================================================================//

    private:
        boost::shared_ptr<boost::thread> mthread;

};
