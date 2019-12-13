// guoguo
inherit NPC;
int ask_party(string str);
void create()
{
    set_name("鲁班", ({ "lu ban", "lu" }));
    set("title", HIY"鬼斧"NOR); 
    set("gender", "男性");
    set("age", 35);
    set("str", 50000);          
    set("dex", 15);
    set("int", 35);
    set("con", 35);
    set("long", "建筑祖师,有鬼斧神差之能,夺天地造化之功,其手艺之佳远近闻名 。\n");      
    set("combat_exp", 1500000000);
    set("shen", 0);     
    set_skill("unarmed", 3500);
    set_skill("force", 3500);
    set_skill("dodge", 3500);
    set_skill("parry", 3500);
    set_skill("axe", 3500);
    set_skill("qufeng", 3500);  
    set_skill("qishang-quan", 3500);            
    set_skill("wuxue-shenfa", 3500);            
    set_skill("king-of-dragon", 3500);          
    set_skill("leiting-axe", 3500);
    map_skill("force", "king-of-dragon");       
    map_skill("dodge", "wuxue-shenfa"); 
    map_skill("axe", "leiting-axe");
    map_skill("parry", "leiting-axe");  
    map_skill("unarmed", "qishang-quan");               
    set_temp("apply/attack", 150);
    set_temp("apply/defense", 150);
    set_temp("apply/armor", 150);
    set_temp("apply/damage", 350);
    set("jiali", 1500); 
    set("max_neili", 5000);     
    set("neili", 15000000);     
    set("max_qi", 1000000);     
    set("max_jingli", 150000);  
    set("jingli", 1500000);     
    set("max_jing", 1000000);   
    set("chat_chance_combat", 150);
    set("chat_msg_combat", ({
        (: perform_action, "axe.zhentian" :),
        (: perform_action, "unarmed.hunpofeiyang" :),           
      }) );
    set("inquiry", ([
        "帮派": (: ask_party :),
      ]) );
    setup();
    carry_object("/d/gaochang/obj/goldaxe")->wield();   
    carry_object("/clone/npc/obj/golden_armor")->wear();        
    carry_object("/clone/cloth/zixuan")->wear();                
}

void init()
{
    add_action("make_bang","mkbang");
}

int ask_party(string arg)
{
    write(YEL"使用方法：mkbang <英文帮派id> <中文帮派名称>\n"NOR);
    return 1;
}

private string *rooms=({
        "dating.c",
        "guanchang.c",
        "beidajie1.c",
        "beidajie2.c",
        "beidajie3.c",
        "beidajie4.c",
        "beidajie5.c",
        "nandajie5.c",
        "nandajie4.c",
        "nandajie3.c",
        "nandajie2.c",
        "nandajie1.c",
        "xidajie1.c",
        "xidajie2.c",
        "xidajie3.c",
        "xidajie4.c",
        "xidajie5.c",
        "dongdajie5.c",
        "dongdajie4.c",
        "dongdajie3.c",
        "dongdajie2.c",
        "dongdajie1.c",
        "leitai.c",
});
int make_bang(string arg)
{
    string partyid,partyname;
    object me;
    int i;
    me=this_player();
    if(!arg || arg=="" || sscanf(arg,"%s %s",partyid,partyname)!=2)
    {
        write(YEL"使用方法：mkbang <英文帮派id> <中文帮派名称>\n"NOR);
        return 1;
    }
    if(!me->query("xy_huiyuan"))
    {
        command("say 对不起，只有会员才能建帮。");
        return 1;
    }
    if (me->query("more_money") < 100)
    {
        command("say 对不起，你的资金不足,买不起地盘，你需要有一百万存款。");
        return 1;
    }
    if(me->query("xyzx_sys/level") < 100)
    {
        command("say 你级数不足，无以成为一帮之主，等你到了一百级再来吧。");    
        return 1;       
    }
    if(sizeof(partyid)==0||sizeof(partyname)==0)
    {
        command("say 帮派id或者帮派名不能为空。");
        return 1;
    }
    if(me->query("party/id"))
    {
        command("say 你必须先退出原来的帮派。");
        return 1;
    }
    for(i=0;i<sizeof(partyid);i++)
    {
        if(partyid[i]<'a' || partyid[0] > 'z')
        {
            command("say 帮派id必须用小写英文字母。");
            return 1;
        }
    }
    if(sizeof(partyname)%2!=0)
    {
        command("say 帮派名必须是中文。");
        return 1;
    }
    for(i=0;i<sizeof(partyname);i++)
    {
        if( partyname[i]<=' ' ) {
            command("say 帮派中文名称不能用控制字元。");
            return 1;
        }
        if( i%2==0 && !is_chinese(partyname[i..(i+1)]) ) {
            command("say 帮派中文名称只能是中文。");
            return 1;
        }
    }
    if(file_size("/d/party/"+partyid)==-2)
    {
        command("say 这个帮派id已经在使用。");
        return 1;
    }

    if(mkdir("/d/party/" + partyid)==0)
    {
        tell_object(me,"帮派目录创建失败，请联系巫师。\n");
        return 1;
    }
    for(i=0;i<sizeof(rooms);i++)
    {
        if(!cp("/d/party/"+rooms[i],"/d/party/"+partyid+"/"))
        {
            tell_object(me,"帮派文件拷贝失败，请联系巫师。\n");
            return 1;
        }
    }
    me->set("party/id",partyid);
    me->set("party/zhu",1);     
    me->add("more_money",-100); 
    me->set("party/name",partyname);    
    me->set("bh_rank",HIC"帮主"NOR);
    message("channel:chat", HIY"\n【帮派精灵】"+HIM"："+me->query("name")+"于今日开帮立会，成立"+partyname+"帮，武林为之大放异彩。\n"NOR,users());
    write_file("/log/cmds/party",sprintf("%s   创建帮派   %s%s on %s\n", me->query("id"),partyname,"("+partyid+")", ctime(time()) ));
    return 1;
}

