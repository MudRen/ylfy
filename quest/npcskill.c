
#include <ansi.h>
inherit NPC;


string *stdskillclass=({"unarmed","dodge","force","blade"});

string *moonskillclass=({"jiuyin-baiguzhao","lingboweibu",
                   "taiji-shengong","wuhu-duanmendao"});    

string *fangcunskillclass=({"nianhua-zhi","tiyunzong",
                   "xiaowuxiang","wuhu-duanmendao"});

string *putuoskillclass=({"jiuyin-baiguzhao","lingboweibu",
                   "taiji-shengong","wuhu-duanmendao"});    

string *hellskillclass=({"jiuyin-baiguzhao","lingboweibu",
                   "taiji-shengong","wuhu-duanmendao"});    
                   
string *longgongskillclass=({"jiuyin-baiguzhao","lingboweibu",
                   "taiji-shengong","wuhu-duanmendao"});    

string *xueshanskillclass=({"jiuyin-baiguzhao","lingboweibu",
                   "taiji-shengong","wuhu-duanmendao"});    

string *wudidongskillclass=({"jiuyin-baiguzhao","lingboweibu",
                   "taiji-shengong","wuhu-duanmendao"});    



int set_std_skills (int level,object ob)
{
   ob->set_skill("unarmed",level);
   ob->set_skill("dodge",level);
   ob->set_skill("parry",level);
   ob->set_sklll("blade",level);
   ob->set_skill("force",level);
}

int set_guai_skills (int level,object ob,string *str)
{
   int i;
   for (i=0;i<4;i++)
    {
      ob->set_skill(str[i],level);
      ob->map_skill(stdskillclass[i],str[i]);
    }       
} 
int set_moon_guai (int level,object ob)
{  
   set_guai_skills(level,ob,moonskillclass);
   ob->set("gender","����");
   ob->set_skill("blade",level);
   ob->set_skill("wuhu-duanmendao",level);
   ob->map_skill("blade","wuhu-duanmendao");
     ob->set("chat_msg_combat", ({
      (: perform_action, "blade.duan" :),
    }) );
}
int carry_moon_weapon()
{
    carry_object("/clone/weapon/hanbing-dao")->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
}

int set_fangcun_guai(int level,object ob)
{  
   set_guai_skills(level,ob,fangcunskillclass);
   ob->set("gender","����");
   ob->set_skill("blade",level);
   ob->set_skill("wuhu-duanmendao",level);
   ob->map_skill("blade","wuhu-duanmendao");
 ob->set("chat_msg_combat", ({
      (: perform_action, "blade.duan" :),
    }) );


}
int carry_fangcun_weapon()
{
    carry_object("/clone/weapon/hanbing-dao")->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
}

int set_putuo_guai(int level,object ob)
{
   set_guai_skills(level,ob,putuoskillclass);
   ob->set("gender","����");
   ob->set_skill("blade",level);
   ob->set_skill("wuhu-duanmendao",level);
   ob->map_skill("blade","wuhu-duanmendao");

 ob->set("chat_msg_combat", ({
      (: perform_action, "blade.duan" :),
    }) );

}
int carry_putuo_weapon()
{  
    carry_object("/clone/weapon/hanbing-dao")->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
}

int set_hell_guai(int level,object ob)
{
   set_guai_skills(level,ob,hellskillclass);
   ob->set("gender","����");
   ob->set_skill("blade",level);
   ob->set_skill("wuhu-duanmendao",level);
   ob->map_skill("blade","wuhu-duanmendao");
 ob->set("chat_msg_combat", ({
      (: perform_action, "blade.duan" :),
    }) );


}
int carry_hell_weapon()
{  
    carry_object("/clone/weapon/hanbing-dao")->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
}

int set_longgong_guai(int level,object ob)
{
   set_guai_skills(level,ob,longgongskillclass);
   ob->set("gender","����");
   ob->set_skill("blade",level);
   ob->set_skill("wuhu-duanmendao",level);
   ob->map_skill("blade","wuhu-duanmendao");

 ob->set("chat_msg_combat", ({
      (: perform_action, "blade.duan" :),
    }) );

}
int carry_longgong_weapon()
{
    carry_object("/clone/weapon/hanbing-dao")->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
}

int set_xueshan_guai(int level,object ob)
{
   set_guai_skills(level,ob,xueshanskillclass);
   ob->set("gender","����");
   ob->set_skill("blade",level);
   ob->set_skill("wuhu-duanmendao",level);
   ob->map_skill("blade","wuhu-duanmendao");
 ob->set("chat_msg_combat", ({
      (: perform_action, "blade.duan" :),
    }) );

}
int carry_xueshan_weapon()
{
    carry_object("/clone/weapon/hanbing-dao")->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
}

int set_wudidong_guai(int level,object ob)
{
    set_guai_skills(level,ob,wudidongskillclass);
   ob->set("gender","����");
   ob->set_skill("blade",level);
   ob->set_skill("wuhu-duanmendao",level);
   ob->map_skill("blade","wuhu-duanmendao");
 ob->set("chat_msg_combat", ({
      (: perform_action, "blade.duan" :),
    }) );


}
int carry_wudidong_weapon()
{   
    carry_object("/clone/weapon/hanbing-dao")->wield();
    carry_object("/clone/cloth/hanbing-jia")->wear();
}
