//tanchuduan.c  谭处端
#include <ansi.h> 
inherit NPC;

void create()
{
        set_name("谭处端", ({"tan chuduan", "tan", "chudan"}));
        set("nickname", HIC"长真子"NOR);
        set("gender", "男性");
        set("age", 53);
        set("long",
             "他脸上筋肉虬结，浓眉大耳，身形魁梧，据说出家前是山东的铁匠。\n"
                "他就是全真七子的二师兄“长真子”谭处端。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing",1350);
        set("max_jing", 1350);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        
        set("combat_exp", 3000000);
        set("score", 50000);
 
        set_skill("force",290);             // 基本内功
        set_skill("tiangang-zhengqi",290);    //天罡正气
        set_skill("unarmed",280);           // 基本拳脚
        set_skill("kongming-quan",280);    //空明拳 
        set_skill("dodge",280);              // 基本躲闪
        set_skill("qixing-huanwei",280 );        //七星换位
        set_skill("parry",290 );             // 基本招架
        set_skill("sword",290 );             // 基本剑法
        set_skill("quanzhen-jianfa",290);        //天罡剑法 
        set_skill("taoism",280 );            //道学心法  
        set_skill("literate",280);           //读书写字  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongmingquan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教", 2, "长老");
        
        setup();
        
       carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();

}


