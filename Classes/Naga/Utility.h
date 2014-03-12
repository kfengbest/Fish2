/*
    Copyright 2012 NAGA.  All Rights Reserved.

    The source code contained or described herein and all documents related
    to the source code ("Material") are owned by NAGA or its suppliers or 
	licensors.  Title to the Material remains with NAGA or its suppliers and 
	licensors.  The Material is protected by worldwide copyright laws and 
	treaty provisions.  No part of the Material may be used, copied, reproduced, 
	modified, published, uploaded, posted, transmitted, distributed, or 
	disclosed in any way without NAGA's prior express written permission.

    No license under any patent, copyright, trade secret or other
    intellectual property right is granted to or conferred upon you by
    disclosure or delivery of the Materials, either expressly, by
    implication, inducement, estoppel or otherwise.  Any license under such
    intellectual property rights must be express and approved by NAGA in
    writing.
*/
/*
	Author		:	Yu Li
	Description	:	Template bases for Singleton objects
	History		:	2012, Initial implementation.
*/
#ifndef __Naga_Utility_H__
#define __Naga_Utility_H__

NAMESPACE_NAGA_BEGIN

/// <description>
/// the string type definition
/// </description>
typedef std::string UTxString;
typedef UTxString::value_type char_t;
typedef std::wstring IString;

// define the assert operator for Naga..
#ifdef  NDEBUG
#define NASSERT(_Expression)     ((void)0)
#else

#ifdef  __cplusplus
extern "C" {
#endif

    void NAGAAPI _Assert(const char_t * _Message, const char_t *_File, unsigned _Line);
#define NASSERT(_Expression) (void)( (!!(_Expression)) || (_Assert(#_Expression, __FILE__, __LINE__), 0) )

#ifdef  __cplusplus
}
#endif

#endif // NDEBUG

#define ARRAY_SIZE(a)	(sizeof(a) / sizeof((a)[0]))

inline IString StringConvert(const UTxString& strHSrc)
{
    return IString(strHSrc.begin(), strHSrc.end());
}

inline UTxString StringConvert(const IString& strISrc)
{
    return UTxString(strISrc.begin(), strISrc.end());
}

/// <description>
/// transform the string to Lower cases
/// </description>
inline UTxString& ToLower(UTxString& str)
{
    STD transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

inline UTxString ToLower(const UTxString& str)
{
    UTxString ret = str;
    STD transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

inline UTxString ToLower(const char* str)
{
    UTxString ret = str;
    STD transform(ret.begin(), ret.end(), ret.begin(), ::tolower);
    return ret;
}

/// <description>
/// return the filename of the full path
/// </description>
inline UTxString FileName(const UTxString& pszPlist)
{
    size_t startPos = pszPlist.find_last_of("/");
    if (startPos == UTxString::npos)
        return pszPlist;
    return pszPlist.substr(startPos+1);
}

void NAGAAPI DebugPrintf(const char* fmt, ...);
void NAGAAPI DebugPrintf(const UTxString& info);
void NAGAAPI Warning(const char*fmt, ...);

namespace detail 
{
    template <typename _Ty, typename = void>
    struct random_traits{ };

    template <typename _Ty> 
    struct random_traits<_Ty, 
        typename std::enable_if<std::is_integral<_Ty>::value>::type>
        {
            typedef std::mt19937 engine_type;
            typedef std::uniform_int_distribution<_Ty> distribution_type;
            typedef typename distribution_type::result_type result_type;

            static inline /*const_expr*/ result_type Min() { return 0; }
            static inline /*const_expr*/ result_type Max() { return 9; }
        };
    
    template <typename _Ty> 
        struct random_traits<_Ty, 
            typename std::enable_if<std::is_floating_point<_Ty>::value>::type>
        {
            typedef std::mt19937 engine_type;
            typedef std::uniform_real_distribution<_Ty> distribution_type;
            typedef typename distribution_type::result_type result_type;

            static inline /*const_expr*/ result_type Min() { return 0.0f; }
            static inline /*const_expr*/ result_type Max() { return 1.0f; }
        };
};

template <typename _Ty>
    class randomizer 
    {       
        typedef detail::random_traits<_Ty> Traits;
        typedef typename Traits::result_type result_type;
        typedef typename Traits::distribution_type distribution_type;
        typedef typename Traits::engine_type engine_type;

        engine_type engine;
        distribution_type dist;
    public:
        randomizer(_Ty m=Traits::Min(), _Ty n=Traits::Max()) 
            : engine(std::random_device()()), dist(m,n){}

        inline result_type operator() () {
            return dist(engine);
        }
    };

NAMESPACE_NAGA_END

#endif // __Naga_Utility_H__
