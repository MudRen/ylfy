// sgangfyshi.c �ͷ�ʹ

#include <ansi.h>
#include "/quest/quest.h"
inherit F_UNIQUE;
inherit NPC;

int ask_me();

void create()
{
       seteuid(getuid());
	set_name("�ڰ���", ({ "heibai zi", "zi" }) );
         set("nickname", HIM "����" NOR);
	set("gender", "����");
	set("age", 48);
	set("long",
		"ֻ������Ȼ���������۶��룬��ò��񳣬\n");
set("combat_exp", 1200000000);
	set("shen_type", 1);
	set("attitude", "peaceful");

set("max_qi", 2000000);
//           set("eff_qi", 300);^M	
//            set("qi", 300);^M	
set("max_jing", 1000000);
//             set("jing", 200);^M	
set("neili", 10000000);
set("max_neili", 2000);
set("jiali", 25000);

set_skill("unarmed", 1200);
set_skill("force", 2700);
set_skill("parry", 1200);
set_skill("dodge", 1300);
set_skill("strike",1500);
set_skill("wuji-shengong",1800);
set_skill("fanyun-zhang",1200);
set_skill("bugui-bufa",1200);

	
	map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("parry", "fanyun-zhang");
	map_skill("strike", "fanyun-zhang");
map_skill("unarmed", "fanyun-zhang");

	
	create_family("ɱ��¥", 2, "ɱ��");
	set("title","ɱ��¥�ͷ�ʹ");

            set("no_get",1);
	set("inquiry", ([
                "ְλ" : (: ask_me :),
	]));

set("chat_chance_combat", 300);		
set("chat_msg_combat", ({	
(: perform_action, "blade.shaqi" :),	
(: perform_action, "unarmed.yunkai" :),     		
(: exert_function, "recover" :),	
}) );	
	setup();

}

int ask_me()
{
        object me;
	mapping fam;
	me=this_player();
        fam = me->query("family");

	if ( ((string)me->query("family/family_name") == "" ) || 
		( (string)me->query("family/family_name") != "" &&
		(string)me->query("family/family_name") != "ɱ��¥" ) )
	{
		message_vision("�ڰ��Ӷ�$N˵�����㲻�Ǳ�����ˣ������������ܸ����㣿\n", me);
		return 1;
	}

if ( (int)me->query("combat_exp") < 10000000 )
	{
		message_vision("�ڰ��Ӷ�$N˵������Ա���Ĺ��׻��������Ժ���˵�ɡ�\n", me);
		return 1;
	}
	message_vision("�ڰ��Ӷ�$N˵������Ա���Ĺ��ײ�С�����ھ�������������Ļ����ɡ�\n", me);
if ( (int)me->query("combat_exp") >= 1500000000 )       	
{
me->set("title","ɱ��¥����ɱ��");	
return 1;	
}
if ( (int)me->query("combat_exp") >= 1000000000 )	
{
me->set("title","ɱ��¥����ɱ��");
return 1;	
}
if ( (int)me->query("combat_exp") >= 500000000 )
	{
                me->set("title", "ɱ��¥����ɱ��");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 200000000 )
	{
               me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 100000000 )
	{
                me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 50000000 )
	{
                me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 10000000 )
	{
                me->set("title","ɱ��¥����ɱ��");
		return 1;
	}
	return 1;
}

