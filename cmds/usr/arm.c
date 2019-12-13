//arm.c

#include <ansi.h>
#include <liebiao.h>
#include <mudlib.h>
#include <combat.h>
inherit F_CLEAN_UP;
inherit F_UNANSI;

string name_temp(object ob,string type);

int main(object me, string arg)
{
        object ob;
        mapping pmap;
        int islook;
        mixed attack_points, dodge_points, parry_points,armor;
        object weapon,second_weapon;
        string line,tmp,wp1,wp2,skill_type;
        if (arg)
	{
                ob = find_player(arg);
                if (! ob) ob = find_living(arg);
                if (! ob) ob = present(arg, environment(me));
                if (! wizardp(me) && (! ob || me->query("couple/child") != ob->query("id"))) 
                {
                      islook=0;   //不是巫师或孩子不能看具体攻击防御数值
                }
                else
                {
                      islook=1;       //可以查看全部数值
                }
                if(!ob)
                {
                     return notify_fail("你要察看谁的装备？\n"); 
                }
               
                       
        }
          if (! ob)
          {
              ob = me;
              islook=1;       //可以查看全部数值
          }
          if( ob==me && me->is_ghost() ) 
          return notify_fail("这些身外之物，生不带来，死不带区，还是算了吧！\n");
           line="";
           tmp="";
           wp1="----";
           wp2="----";
       
  	 weapon= ob->query_temp("weapon");
         second_weapon= ob->query_temp("secondary_weapon");
         if(weapon)
         { 
                 wp1=weapon->query("name");
                
         }
         if(second_weapon)
         {
                  wp2=second_weapon->query("name");
                 
         }
          
   	

 write(HIG+" ["+ob->query("name")+"] 装备了下列物品：                    \n"NOR);                    
 line += sprintf(HIY"├──────────────────────────────────┤\n");  
 tmp += sprintf(""HIY"│"NOR"%20s "WHT"[头部]__"NOR+BLU"   ███   "WHT"__[右手]"NOR" %-20s"NOR"\n",name_temp(ob,"armor/head"), wp1);
 tmp += sprintf(""HIY"│"NOR"%20s "WHT"[颈部]__"NOR+BLU"   "NOR" o"BLU"█"NOR"o "NOR"   "WHT"__[手腕]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/neck"), name_temp(ob,"armor/wrists"));
 tmp += sprintf(""HIY"│"NOR"%20s "WHT"[背部]__"NOR+BLU"   "WHT"▂"NOR"﹀"WHT"▂"NOR+BLU" ▌"WHT"__[手部]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/surcoat"), name_temp(ob,"armor/hands"));
 tmp += sprintf(""HIY"│"NOR"%20s "WHT"[衣服]__"NOR+BLU" ▅███"BLU"▅"NOR+WHT" __[护甲]"NOR" %-20s"NOR"\n",name_temp(ob,"armor/cloth"), name_temp(ob,"armor/armor"));
 tmp += sprintf(""HIY"│"NOR"%20s "WHT"[盾牌]__"NOR+BLU" ▌  █     "WHT"__[腰部]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/shield"),name_temp(ob,"armor/waist"));
 tmp += sprintf(""HIY"│"NOR"%20s "WHT"[左手]__"NOR"   "BLU" ▌"HIR""NOR+BLU" ▌   "WHT"__[裤子]"NOR" %-20s"NOR"\n",wp2, name_temp(ob,"armor/pants"));
 tmp += sprintf(""HIY"│"NOR"%20s "WHT"[戒指]__"NOR+BLU" ▄█  █▄ "WHT"__[足部]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/finger"), name_temp(ob,"armor/boots"));
  tmp += sprintf(HIY"├──────────────────────────────────┤\n"NOR);
 line += tmp;
 if(islook)
 {
      //计算命中，闪避和招架
      //--------------------------------------------------------
        pmap = me->query_skill_prepare();
        if( objectp(weapon = me->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else if ( sizeof(pmap) == 0)
		skill_type = "unarmed";
	else if ( sizeof(pmap) == 1)
		skill_type = (keys(pmap))[0];
	else if ( sizeof(pmap) == 2)
	{
		if ( (keys(pmap))[0] >= (keys(pmap))[1] )
			skill_type = (keys(pmap))[0];
		else
			skill_type = (keys(pmap))[1];
	}
        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DODGE);
	armor = to_int(sqrt(to_float(ob->query_temp("apply/armor")/1000))); //2016.8.13添加 伤害减免
      //--------------------------------------------------------
        line += sprintf(""YEL"│"HIR"【武器攻击】: "HIC"%7d\n"NOR, ob->query_temp("apply/damage"));
		line += sprintf(""YEL"│"HIM"【防具抵抗】: "HIC"%7d\n"NOR, ob->query_temp("apply/armor"));
		line += sprintf(""YEL"│"HIM"【伤害减免】: "HIC"%4d%%\n"NOR, armor );
        line += sprintf(""YEL"│"HIR"【命 中】: " HIW "%10s\n"NOR,floatp(attack_points)?(attack_points+1+"")[0..<8]:(attack_points+1+""));
		line += sprintf(""YEL"│"HIM"【闪 避】: " HIW "%10s\n"NOR,floatp(dodge_points)?(dodge_points+1+"")[0..<8]:(dodge_points+1+""));
		line += sprintf(""YEL"│"YEL"【招 架】: " HIW "%10s\n"NOR,floatp(parry_points)?(parry_points+1+"")[0..<8]:(parry_points+1+""));
     //--------------------------------------------------------------
     line += sprintf(HIM"├──────────────────────────────────┤\n"); 
 }  
     line += ob->suit(ob);   //套装信息   
     line += sprintf(HIM"├──────────────────────────────────┤\n"NOR); 
       write(line);
 
        return 1;
}
string name_temp(object ob,string type)
{
    string name;
    object obj;
    if( objectp(obj=ob->query_temp(type)) ) 
    {
       name = obj->query("name");
       //name = filter_color(name);
    }
    else
    {
       name = "----";
    }
   return name;
}

int help (object me)
{
        write(@HELP
指令格式: arm
 
可列出你(你)目前身上所携带的所有物品。
 
 
HELP );
        return 1;
}