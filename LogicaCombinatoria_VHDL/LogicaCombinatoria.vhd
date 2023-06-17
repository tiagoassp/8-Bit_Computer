------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (15/06/2023, 19:42:51)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 2.50.200 (Feb 18, 2022)
-- Copyright (c) 2002-2022 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.all;


ENTITY LogicaCombinatoria IS
  PORT( 
    --------------------------------------> Inputs:
    iID0001:      IN  std_logic;
    iID0002:      IN  std_logic;
    iID0003:      IN  std_logic;
    iID0004:      IN  std_logic;
    iID0006:      IN  std_logic;
    iID0007:      IN  std_logic;
    iID0008:      IN  std_logic;
    iID0009:      IN  std_logic;
    iID0245:      IN  std_logic 
    ------------------------------------------------------
    );
END LogicaCombinatoria;


ARCHITECTURE structural OF LogicaCombinatoria IS 

  ----------------------------------------> Components:
  COMPONENT NOT_gate IS
    PORT( I: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT AND5_gate IS
    PORT( I0,I1,I2,I3,I4: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT AND6_gate IS
    PORT( I0,I1,I2,I3,I4,I5: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT OR2_gate IS
    PORT( I0,I1: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT OR3_gate IS
    PORT( I0,I1,I2: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT OR4_gate IS
    PORT( I0,I1,I2,I3: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;
  --
  COMPONENT OR8_gate IS
    PORT( I0,I1,I2,I3,I4,I5,I6,I7: IN std_logic;
          O: OUT std_logic );
  END COMPONENT;

  ----------------------------------------> Signals:
  SIGNAL S001: std_logic;
  SIGNAL S002: std_logic;
  SIGNAL S003: std_logic;
  SIGNAL S004: std_logic;
  SIGNAL S005: std_logic;
  SIGNAL S006: std_logic;
  SIGNAL S007: std_logic;
  SIGNAL S008: std_logic;
  SIGNAL S009: std_logic;
  SIGNAL S010: std_logic;
  SIGNAL S011: std_logic;
  SIGNAL S012: std_logic;
  SIGNAL S013: std_logic;
  SIGNAL S014: std_logic;
  SIGNAL S015: std_logic;
  SIGNAL S016: std_logic;
  SIGNAL S017: std_logic;
  SIGNAL S018: std_logic;
  SIGNAL S019: std_logic;
  SIGNAL S020: std_logic;
  SIGNAL S021: std_logic;
  SIGNAL S022: std_logic;
  SIGNAL S023: std_logic;
  SIGNAL S024: std_logic;
  SIGNAL S025: std_logic;
  SIGNAL S026: std_logic;
  SIGNAL S027: std_logic;
  SIGNAL S028: std_logic;
  SIGNAL S029: std_logic;
  SIGNAL S030: std_logic;
  SIGNAL S031: std_logic;
  SIGNAL S032: std_logic;
  SIGNAL S033: std_logic;
  SIGNAL S034: std_logic;
  SIGNAL S035: std_logic;
  SIGNAL S036: std_logic;
  SIGNAL S037: std_logic;
  SIGNAL S038: std_logic;


BEGIN -- structural

  ----------------------------------------> Input:
  S038 <= iID0001;
  S037 <= iID0002;
  S036 <= iID0003;
  S035 <= iID0004;
  S001 <= iID0006;
  S013 <= iID0007;
  S005 <= iID0008;
  S006 <= iID0009;
  S008 <= iID0245;

  ----------------------------------------> Constants:
  S028 <= '0';

  ----------------------------------------> Component Mapping:
  C026: AND5_gate PORT MAP ( S013, S034, S005, S012, S015, S002 );
  C051: NOT_gate PORT MAP ( S001, S034 );
  C052: NOT_gate PORT MAP ( S013, S004 );
  C053: NOT_gate PORT MAP ( S005, S014 );
  C054: NOT_gate PORT MAP ( S006, S015 );
  C133: AND5_gate PORT MAP ( S004, S034, S005, S012, S006, S032 );
  C134: AND5_gate PORT MAP ( S004, S034, S005, S003, S006, S033 );
  C185: AND5_gate PORT MAP ( S013, S034, S014, S012, S006, S022 );
  C186: AND5_gate PORT MAP ( S013, S034, S014, S003, S006, S031 );
  C247: AND6_gate PORT MAP ( S012, S014, S013, S015, S001, S007, 
                             S026 );
  C248: AND6_gate PORT MAP ( S003, S014, S013, S015, S001, S007, 
                             S010 );
  C249: AND6_gate PORT MAP ( S012, S014, S013, S015, S001, S008, 
                             S029 );
  C250: AND6_gate PORT MAP ( S003, S014, S013, S015, S001, S008, 
                             S011 );
  C345: NOT_gate PORT MAP ( S008, S007 );
  C366: OR8_gate PORT MAP ( S033, S031, S032, S010, S002, S026, 
                            S024, S011, S016 );
  C450: AND5_gate PORT MAP ( S014, S013, S015, S034, S012, S027 );
  C451: AND5_gate PORT MAP ( S014, S013, S015, S034, S003, S017 );
  C508: OR3_gate PORT MAP ( S016, S021, S017, S009 );
  C517: OR2_gate PORT MAP ( S024, S031, S018 );
  C542: OR2_gate PORT MAP ( S021, S033, S020 );
  C556: OR4_gate PORT MAP ( S022, S026, S032, S027, S023 );
  C580: OR2_gate PORT MAP ( S032, S026, S025 );
  C615: OR2_gate PORT MAP ( S030, S031, S030 );
  C631: OR3_gate PORT MAP ( S033, S021, S022, S019 );
  C711: NOT_gate PORT MAP ( S038, S021 );
  C712: NOT_gate PORT MAP ( S037, S024 );
  C713: NOT_gate PORT MAP ( S036, S012 );
  C714: NOT_gate PORT MAP ( S035, S003 );
END structural;
