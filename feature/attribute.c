// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
//2015.10.30增加int post 判断纯后天
#include <dbase.h>
#include <skill.h>
int query_str(int post)
{
    int improve = query_skill("unarmed", 1) / 10;
    if ( query_skill("unarmed",1)
      || query_skill("strike", 1)
      || query_skill("finger", 1)
      || query_skill("cuff", 1)
      || query_skill("hand", 1)
      || query_skill("claw", 1))
    {
        if ( query_skill("strike", 1) >= improve * 10 )
            improve = (int)query_skill("strike", 1) / 10;
        if ( query_skill("finger", 1) >= improve * 10)
            improve = (int)query_skill("finger", 1) / 10;
        if ( query_skill("cuff", 1) >= improve * 10)
            improve = (int)query_skill("cuff", 1) / 10;
        if ( query_skill("hand", 1) >= improve * 10)
            improve = (int)query_skill("hand", 1) / 10;
        if ( query_skill("claw", 1) >= improve * 10)
            improve = (int)query_skill("claw", 1) / 10;
    }
    return (int)query("str") + (int)query("jiali") + improve + 
	       (post?0:query_temp("apply/strength")+ query_temp("suit_eff/strength"));
}
int query_int(int post)
{
    return (int)query("int") + (int)query_skill("literate", 1) / 10 + 
	       (post?0:(query_temp("apply/intelligence") + query_temp("suit_eff/intelligence")));
}
int query_con(int post)
{
    return (int)query("con") + (int)query_skill("force", 1) / 10 + 
	    (post?0:(query_temp("apply/constitution") + query_temp("suit_eff/constitution")));
}
int query_dex(int post)
{
    int i;
    i=(this_object()->query_encumbrance()*100)/this_object()->query_max_encumbrance();
    if (i>50)
        return (int)query("dex")+ (int)query_skill("dodge", 1) / 10-(i-30)/10 +
	      (post?0:(query_temp("apply/dexerity") + query_temp("suit_eff/dexerity")));
    else
        return (int)query("dex") + (int)query_skill("dodge", 1) / 10 + 
	   (post?0:(query_temp("apply/dexerity") + query_temp("suit_eff/dexerity")));
}
int query_kar()
{
    return (int)query("kar")+ query_temp("apply/karma");
}
int query_per()
{
    return (int)query("per") + query_temp("apply/personality");
}
