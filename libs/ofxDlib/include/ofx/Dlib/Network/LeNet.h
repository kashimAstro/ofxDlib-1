//
// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier:	MIT
//


#pragma once


#include "dlib/dnn.h"


namespace ofx {
namespace Dlib {
namespace Network {


// From dlib:
// Now let's define the LeNet.  Broadly speaking, there are 3 parts to a network
// definition.  The loss layer, a bunch of computational layers, and then an input
// layer.  You can see these components in the network definition below.
//
// The input layer here says the network expects to be given matrix<unsigned char>
// objects as input.  In general, you can use any dlib image or matrix type here, or
// even define your own types by creating custom input layers.
//
// Then the middle layers define the computation the network will do to transform the
// input into whatever we want.  Here we run the image through multiple convolutions,
// ReLU units, max pooling operations, and then finally a fully connected layer that
// converts the whole thing into just 10 numbers.
//
// Finally, the loss layer defines the relationship between the network outputs, our 10
// numbers, and the labels in our dataset.  Since we selected loss_multiclass_log it
// means we want to do multiclass classification with our network.   Moreover, the
// number of network outputs (i.e. 10) is the number of possible labels.  Whichever
// network output is largest is the predicted label.  So for example, if the first
// network output is largest then the predicted digit is 0, if the last network output
// is largest then the predicted digit is 9.

using LeNet = dlib::loss_multiclass_log<
                                        dlib::fc<10,
                                        dlib::relu<dlib::fc<84,
                                        dlib::relu<dlib::fc<120,
                                        dlib::max_pool<2,2,2,2,dlib::relu<dlib::con<16,5,5,1,1,
                                        dlib::max_pool<2,2,2,2,dlib::relu<dlib::con<6,5,5,1,1,
                                        dlib::input<dlib::matrix<unsigned char>>
                                        >>>>>>>>>>>>;
 
template <typename SUBNET> using tlnet0  = dlib::add_tag_layer< 1100 + 0, SUBNET>;
template <typename SUBNET> using tlnet1  = dlib::add_tag_layer< 1100 + 1, SUBNET>;
template <typename SUBNET> using tlnet2  = dlib::add_tag_layer< 1100 + 2, SUBNET>;
template <typename SUBNET> using tlnet3  = dlib::add_tag_layer< 1100 + 3, SUBNET>;
template <typename SUBNET> using tlnet4  = dlib::add_tag_layer< 1100 + 4, SUBNET>;
template <typename SUBNET> using tlnet5  = dlib::add_tag_layer< 1100 + 5, SUBNET>;
template <typename SUBNET> using tlnet6  = dlib::add_tag_layer< 1100 + 6, SUBNET>;
template <typename SUBNET> using tlnet7  = dlib::add_tag_layer< 1100 + 7, SUBNET>;
template <typename SUBNET> using tlnet8  = dlib::add_tag_layer< 1100 + 8, SUBNET>;
template <typename SUBNET> using tlnet9  = dlib::add_tag_layer< 1100 + 9, SUBNET>;
template <typename SUBNET> using tlnet10  = dlib::add_tag_layer< 1100 + 10, SUBNET>;

using TaggedLeNet = dlib::loss_multiclass_log<
                    tlnet0<dlib::fc<10,
                    tlnet1<dlib::relu<
                    tlnet2<dlib::fc<84,
                    tlnet3<dlib::relu<
                    tlnet4<dlib::fc<120,
                    tlnet5<dlib::max_pool<2,2,2,2,
                    tlnet6<dlib::relu<
                    tlnet7<dlib::con<16,5,5,1,1,
                    tlnet8<dlib::max_pool<2,2,2,2,
                    tlnet9<dlib::relu<
                    tlnet10<dlib::con<6,5,5,1,1,
                    dlib::input<dlib::matrix<unsigned char>
                    >>>>>>>>>>>>>>>>>>>>>>>>;


    
} } } // namespace ofx::Dlib::Network