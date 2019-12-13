// Room: /d/dali/yamen2.c

inherit ROOM;

void create()
{
	set("short", "ÑÃÃÅÕıÌü");
	set("long", @LONG
ÌÃÉÏ¶«Î÷ÓĞÁ½¸ùéº×¡£¬¹Ò×ÅÒ»·ù¶ÔÁª£¬µ«ÊÇÄãÎŞĞÄÏ¸¿´¡£ÕıÇ½ÉÏĞü¹ÒÒ»¸öºáØÒ£¬
ÉÏÊé¡°[1;33mÕı´ó¹âÃ÷[2;37;0m¡±ËÄ¸ö½ğ¹âÉÁÉÁµÄ´ó×Ö¡£Öª¸®Õı×øÔÚÎÄ°¸ºóÅúÔÄÎÄÊé£¬Ê¦Ò¯ËæÊÌÔÚºó¡£
·²´óÀí¹ÙÔ±¶¼¿ÉÒÔÀ´ÕâÀï¼©ÄÃ£¨£ê£é£î£á£©ÏëÒªµÄÒÉ·¸¡£
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yamen",
]));

                 set("objects", ([
                __DIR__"npc/cheng" : 1,
                __DIR__"npc/shiye" : 1,
        ]));

         
	setup();
}

void init()
{
	add_action("do_jina","jina");
}

void gethim(object target,object me)
{
	if ( !objectp(target) || !objectp(me) ) return;

	if ( environment(me) == this_object() )
	{
		message("vision", "¼¸¸ö¹Ù±ø³åÁË½øÀ´£¬¶ş»°²»Ëµ£¬¼ÜÆğ"+target->name()+"£¬´Ò´ÒÃ¦Ã¦ÍùÍâÀëÈ¥¡£\n", environment(target));
		target->move(this_object());
		message_vision("$N±»¹Ù±øÑºÁË½øÀ´¡£\n$n´óºÈÒ»Éù£¬"+target->name(1)+"£¬ÄãÕâÉ±ÈË·¸£¬ÄÉÃüÀ´£¡\n", target, me);
		me->kill_ob(target);
		me->start_busy(3);
		target->kill_ob(me);
		target->start_busy(2+random(3));
	}
}

int do_jina(string arg)
{
	object me, target;

	me = this_player();

	if ( !objectp(me) ) return 0;
	if ( !arg ) return notify_fail("ÄãÒªÏÂÁî¼©ÄÃË­£¿\n");
	if ( (string) me->query("class") != "officer" ) 
		return notify_fail("Äã²»ÊÇ´óÀí¹ÙÔ±£¬²»¿É¼©ÄÃÒÉ·¸£¡\n");	
	/*if( me->query("combat_exp",1) <=100000000 )
		return notify_fail("Ö»ÓĞ´óÀí¹úÓùÁîÌùÉíÊÌÎÀÒÔÉÏ¹Ù¼¶²Å¿ÉÒÔ¼©ÄÃÒÉ·¸£¡\n");*/
	if ( (int)me->query("jing") < 100 ) 
		return notify_fail("ÄãµÄĞÄÉñ²»¹»£¡\n");
	
	me->add("jing",-100);
	
	if ( !objectp(target = find_living(arg)) ) 
		return notify_fail("ÕÒ²»µ½ÄãÏëÒªµÄÒÉ·¸£¡\n");
	if ( !environment(target) || wizardp(target) ) 
		return notify_fail("ÕÒ²»µ½ÄãÏëÒªµÄÒÉ·¸£¡\n");	
	if ( target->is_ghost() )
		return notify_fail("ÕÒ²»µ½ÄãÏëÒªµÄÒÉ·¸£¡\n");
	if ( target == me ) 
		return notify_fail("×Ô¼º¼©ÄÃ×Ô¼º£¬ÄãÃ»Ã«²¡°É£¿\n");
	if ( !(int)target->query_condition("killer") )
	    return notify_fail(target->name(1)+"ºÃÏó²¢Ã»ÓĞ×÷¼é·¸¿Æ£¬ÄãÎŞÈ¨¼©ÄÃ"+gender_pronoun(target->query("gender"))+"¡£\n");
	/*if (target->query("age") < 18) return notify_fail(target->name(1) + "ÉĞÄêÓ×£¬»¹ÊÇÔİÇÒ·Å¹ıËû°É¡£\n");*/
	if ( file_name(environment(target)) == "/clone/misc/block" )
		return notify_fail(target->name(1) + "ÏÖÔÚÕıÔÚ¼àÓüÀï·´Ê¡Ë¼¹ı£¬Ã»±ØÒªÔÙ¼©ÄÃÁË¡£\n");
	
	message_vision("$N´óÉùÁîÏÂ£ºÀ´ÈËÄÇ£®£®°Ñ"+target->name(1)+"¸øÎÒÄÃÀ´£¡£¡\n",me);
	remove_call_out("gethim");
	call_out("gethim",5, target, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if ( me->is_fighting() && dir=="east" ) 
		return notify_fail("ÄãÏÖÔÚ²»¿ÉÀë¿ª£¡\n");
	
	return 1;
}