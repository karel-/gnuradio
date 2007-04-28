/*
 * Copyright 2006,2007 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef INCLUDED_GR_HIER_BLOCK2_DETAIL_H
#define INCLUDED_GR_HIER_BLOCK2_DETAIL_H

#include <gr_hier_block2.h>
#include <gr_simple_flowgraph_detail.h>
#include <boost/utility.hpp>

class gr_hier_block2_detail : boost::noncopyable
{
private:
    friend class gr_hier_block2;
    friend class gr_runtime_impl;
    
    // Constructor--it's private, only friends can instantiate
    gr_hier_block2_detail(gr_hier_block2 *owner);

    // Private implementation data
    gr_hier_block2 *d_owner;
    gr_simple_flowgraph_sptr d_fg;
    gr_endpoint_vector_t d_inputs;
    gr_endpoint_vector_t d_outputs;
        
    // Private implementation methods
    void connect(gr_basic_block_sptr src, int src_port, 
                 gr_basic_block_sptr dst, int dst_port);
    void disconnect(gr_basic_block_sptr, int src_port, 
                    gr_basic_block_sptr, int dst_port);
    void assign_input(int my_port, int port, gr_basic_block_sptr block);
    void assign_output(int my_port, int port, gr_basic_block_sptr block);
    void flatten(gr_simple_flowgraph_sptr sfg);
    gr_endpoint resolve_port(int port, bool is_input);
    gr_endpoint resolve_endpoint(const gr_endpoint &endp, bool is_input);

public:
    ~gr_hier_block2_detail();
};

#endif /* INCLUDED_GR_HIER_BLOCK2_DETAIL_H */
