//
//  Header.h
//  TD03
//
//  Created by Johan Medioni on 02/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef TD03_Header_h
#define TD03_Header_h

class CinemaException {
public:
    CinemaException(const std::string& m) : info(m){} 
    const std::string& GetInfo() const { return info; }
private:
    std::string info;
};

#endif
